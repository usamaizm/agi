// agi.c

agi init_agi() {
    agi agi;
    agi.language = init_language_module();
    agi.vision = init_vision_module();  // Call the vision module initialization function
    agi.reasoning = init_reasoning_module();
    agi.kg = init_knowledge_graph();
    return agi;
}
