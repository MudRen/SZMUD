// Code of ShenZhou
// ʯ��
// Dong  01/20/97.
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{   set("short", "ʯ��");
    set("long", @LONG
Խ������Խ�����������㿪ʼ�е�һ˿���⣬ӭ��һ��ů������
������ԭ��ǰ����һ��Ȼ����Ȫ��Ȫˮ��Ө͸������ɫ��ζ��������
ԡ����Ȫ���ܳ������滨��ݡ�
LONG);

    set("exits", ([ /* sizeof() == 2 */
	"up" : __DIR__"shijie4",
	"down" : __DIR__"songguan",
		 ])
	 );
    setup();
    replace_program(ROOM);
}
