// Code of ShenZhou
// �ɹ���
// Dong  01/20/97.
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{   set("short", "�ɹ���");
    set("long", @LONG
�ɹ����ڵ��Ϸ��£���ǰ����ˮ��ɳ��ӣ���Χ�����纣������
�ľ�����ǰɢ����������������������������̶������Щˮ̶��ǳ��
ͬ���Ϸ��͵�Ӱ��ʯɫ���죬��ˮӳ�ɸ���ɫ�ʣ�������Ŀ��
LONG);

    set("exits", ([ /* sizeof() == 1 */
	"up" : __DIR__"shijie5",
		 ])
	 );
    setup();
    replace_program(ROOM);
}
