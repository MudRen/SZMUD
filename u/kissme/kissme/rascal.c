inherit NPC;

void create()
{
    set_name("С��å",({"rascal"}));
    set("long","����ȥ�������׶�ú��ӡ�\n");
    set("age",25);
    set("combat_chat_chance",5);
    set("combat_chat_msg",({
        "С��å��������Ӹ��㳤�����ԣ�\n",
        }));
    setup();
    add_money("silver",30);
}

