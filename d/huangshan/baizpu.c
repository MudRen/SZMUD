// Code of ShenZhou
// ������
// Dong  01/20/97.
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{   set("short", "������");
    set("long", @LONG
һ������������̶�����ƶ���֮�䣬����ǧ�߷�к���£��ʵ���
�������١�����ˮ������ϸ��������ɴ��翣��ֳư���Ȫ������Ȫ
�Ͻв�ˮԴ�������а���̶���Ա���ר���ο͹��ٵĹ���ͤ��
LONG);

    set("exits", ([ /* sizeof() == 2 */
	"southwest" : __DIR__"wenquan",
	"northeast" : __DIR__"shanlu1",
		 ])
	 );
    setup();
    replace_program(ROOM);
}
