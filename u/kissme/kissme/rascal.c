inherit NPC;

void create()
{
    set_name("小流氓",({"rascal"}));
    set("long","看上去长的满凶恶得汉子。\n");
    set("age",25);
    set("combat_chat_chance",5);
    set("combat_chat_msg",({
        "小流氓骂到：让老子给你长长记性！\n",
        }));
    setup();
    add_money("silver",30);
}

