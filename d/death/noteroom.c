// Code of ShenZhou
// Room: /d/death/noteroom.c
// mantian may/2001
// xQin 05/01

inherit ROOM;
#include <ansi.h>
void init();

void create()
{
        set("short", "��ҷ����¼��");
        set("long", @LONG
�����Ƿ����¼�ң��ṩ��ʦ��¼��ұ�ץ��ԭ������������ʦ����
���������Ƭ��֮�ʶ��ͷŴ��ˡ�
LONG );
	
        set("exits", ([
        "east" : "/d/wizard/wizard_room",
        "west" :   __DIR__"blkbot" ]));

        set("valid_startroom", 1);
        set("no_fight", "1");
        set("no_clean_up", 0);
        set("cost", 0);
        setup();
	call_other("/clone/board/note1_b", "???");

}
/*
void init()
{
	object me = this_player();
	if (wizhood(me) == "(player)")
	{
		write(HIW "\n�ⲻ��������ĵط�\n\n" NOR);
		me->set("startroom", "/d/death/death");
		me->move("/d/death/death.c");
		return 0;
	}
}
*/

