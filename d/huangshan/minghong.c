// Code of ShenZhou
// ����Ȫ
// Dong  01/20/97.
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{   set("short", "����Ȫ");
    set("long", @LONG
Ȫˮ�ɸ�ɽʯ����Ȼ���£������һ�鳤���ɣ�����ߣ������
�ٵĴ�ʯ����ʯ��Ȫˮ���û��·��������ö�����������Ŀ��������
��������翡�Ȫ������ʯһ�飬�ഫ����λ�ɽʱ���ڴ�������Ȫ��
������������֪�������ڴ�ʯ֮�ϡ�
LONG);

    set("exits", ([ /* sizeof() == 1 */
	"east" : __DIR__"renzipu",
		 ])
	 );
    setup();
    replace_program(ROOM);
}
