// Room: /d/wizard/wizard_room.c
// huaishi Aug 14, 2001
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIW"��ͼ���������"+NOR);
        set("long",
  "��������ϯ��ͼ����������������ֵĻ����ң���������ǽ�ϣ�������ʮ��\n"
+"�����͸���ı��������ŵ���һ�˿�ǽ�����У�����ʯ�����״����ڹ��󣬸�\n"
+"������ľ�ʯ��Ϊ�����һ���������ݵ���ζ���м�������Ϸ���һ��"+HIW+"����ͼ��\n"
+"�����԰� ��"+NOR+"(board)����˵�������������ｻ���йص�ͼ�����䡢���ص���ƺ�\n"
+"��̷����֪ʶʱ���µġ�\n");
        set("exits", ([ 
                  "out" : "/d/wizard/meeting_room",

]));
        
        set("no_fight", 1);
        set("no_clean_up", 0);
        set("valid_startroom", 1);
        set("cost", 0);
        setup();
        call_other("/clone/board/room_b", "???");
        call_other("/clone/board/room_pro", "???");
}

void init()
{
        object me = this_player();

        if (wizhood(me) == "(player)")
                me->move("/d/death/death.c");
}
