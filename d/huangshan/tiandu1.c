// Code of ShenZhou
// �춼��
// Dong  01/20/97.
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{   set("short", "�춼��");
    set("long", @LONG
���ֽŲ������ⴹֱ�ľ��ڣ���ʱҪϥ�����������ӿ��ڡ�����
һ������㲻�ò�ͣ����ЪЪ���������ܵľ�ɫ�����ֵ�����ʯ��̬
�������������춼���������ţ������ǽ��������㣬����ά��άФ��
LONG);

    set("exits", ([ /* sizeof() == 2 */
	"down" : __DIR__"tianmen",
	"up" : __DIR__"jiyubei",
		 ])
	 );
    setup();
    replace_program(ROOM);
}
