// Code of ShenZhou
// ������
// Dong  01/20/97.
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{   set("short", "������");
    set("long", @LONG
��Ȫ����¯���޺��������к���£����������������ڿն�
�����پŵ���ÿ��һ̶����ƾ���̶��ǰ����ʫ��������Ȫ���ÿ�®
�٣��ͱڳ���Ҿ�������
LONG);

    set("exits", ([ /* sizeof() == 1 */
	"northwest" : __DIR__"yungu",
		 ])
	 );
    setup();
    replace_program(ROOM);
}
