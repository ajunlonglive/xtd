#include "../../../../include/xtd/speech/synthesis/speech_synthesizer.h"
#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/speech_synthesizer.h>
#undef __XTD_CORE_NATIVE_LIBRARY__
#include <functional>

using namespace std;
using namespace xtd;
using namespace xtd::speech::synthesis;

speech_synthesizer::speech_synthesizer() {
  data_->handle = native::speech_synthesizer::create();
}

speech_synthesizer::~speech_synthesizer() {
  native::speech_synthesizer::destroy(data_->handle);
}

void speech_synthesizer::speak(const ustring& text_to_speak) {
  data_->used_prompt = &data_->prompt;
  data_->used_prompt->data_->text_to_speak = text_to_speak;
  speak(*data_->used_prompt);
}

void speech_synthesizer::speak(xtd::speech::synthesis::prompt& prompt) {
  data_->used_prompt = &prompt;
  on_speak_started();
  native::speech_synthesizer::speak(data_->handle, data_->used_prompt->data_->text_to_speak);
  data_->used_prompt->data_->synthesizer = this;
  on_speak_completed();
}

xtd::speech::synthesis::prompt& speech_synthesizer::speak_async(const ustring& text_to_speak) {
  data_->used_prompt = &data_->prompt;
  data_->used_prompt->data_->text_to_speak = text_to_speak;
  speak_async(*data_->used_prompt);
  return *data_->used_prompt;
}

void speech_synthesizer::speak_async(xtd::speech::synthesis::prompt& prompt) {
  data_->used_prompt = &prompt;
  on_speak_started();
  native::speech_synthesizer::speak_async(data_->handle, data_->used_prompt->data_->text_to_speak, bind(&speech_synthesizer::on_speak_completed, this));
  data_->used_prompt->data_->synthesizer = this;
}

void speech_synthesizer::on_speak_completed() {
  set_state(synthesizer_state::ready);
  speak_completed(*this, {false, nullptr, data_->used_prompt});
}

void speech_synthesizer::on_speak_started() {
  set_state(synthesizer_state::speaking);
  speak_started(*this, {false, nullptr, data_->used_prompt});
}

void speech_synthesizer::set_state(synthesizer_state value) {
  if (data_->state != value) {
    auto previous_state = data_->state;
    data_->state = value;
    state_changed(*this, {previous_state, data_->state});
  }
}
