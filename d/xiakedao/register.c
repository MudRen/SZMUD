//Cracked by Roath
// Room: /adm/register/reg_room.c

inherit ROOM;

void create()
{
        set("short", "���͵�������");
        set("long", @LONG
����һ������������������һ�Ŵ����ӣ����ϰ���һ�����ı�
�ӡ��������棬��ǽ����һ����ܣ������������˺����ϲ��ı�
�ӡ�һ���������������ᷭ�����Ǵ��ӣ�����ʱ������������޸�
ʲ�ᡣ
LONG);

        set("objects", ([
                "/d/xiakedao/npc/mux" : 1,
        ]));

        set("invalid_startroom", 1);
        set("no_fight", "1");
        setup();
//      load_object("/daemon/board/wizard");
//      replace_program(ROOM);
}
void init()
{
        object ob = this_player();

        if (!wizardp(ob)) {
                add_action("block_cmd","",1);
//                ob->set("startroom", "/d/death/death");
                ob->set("block", 1);
        }
}

int block_cmd()
{
        string cmd;
        cmd = query_verb();
        if ( cmd == "quit" || cmd == "goto" || cmd == "suicide" || cmd == "register" || cmd == "tell" || cmd == "say" || cmd == "reply" || cmd == "look")
                return 0;
        return 1;
}

