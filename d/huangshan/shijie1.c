// Code of ShenZhou
// ʯ��
// Dong  01/20/97.
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{   set("short", "ʯ��");
    set("long", @LONG
һ��������ʯ���������죬��˵����ǧ�Ű�ʯ�����������ⳤ��
��ʯ·�ϣ�ÿ��һ��ʯ�����Ͷ�������������һ����ᡣ�����ܣ�����
Ǳ���˺��ס�ɽ��֮�����������ɫ����������һλ������ɴ���ٸ���
LONG);

    set("exits", ([ /* sizeof() == 2 */
	"up" : __DIR__"qinglian",
	"down" : __DIR__"shijie2",
		 ])
	 );
    setup();
    replace_program(ROOM);
}
