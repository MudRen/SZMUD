// Code of ShenZhou
// ʼ�ŷ�
// Dong  01/20/97.
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{   set("short", "ʼ�ŷ�");
    set("long", @LONG
ʼ�ŷ���������ʯ��嶦��������澰��Ȼ�����϶�������ʯ��
����ʫ�黭�⡣�����������Զ��ʯ�������һ����ʯ���β�������
��ͬ���ᴺ�����Ǳ���Ϊʮ���޺����Ϻ������޺����ߵʹ�С��һ��
��̬���⡣
LONG);

    set("exits", ([ /* sizeof() == 1 */
	"westdown" : __DIR__"mengbi",
		 ])
	 );
    setup();
    replace_program(ROOM);
}
