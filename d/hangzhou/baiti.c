// Code of ShenZhou
// �׵�
// Dong  11/03/1996.
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{   set("short", HIG"�׵�"NOR);
    set("long", @LONG
�׵̺ᵩ���ϣ��������ֳ������������������������������ҡ�
ÿ�괺������������˿���̣��������մ�Ц�����׾������С��һ���
�������ۣ�ǳ�ݲ���û���㡣������в��㣬���������ɳ�̡���
����������ľ�ɫ���������߹��˽����ű��ǡ�ƽ�����¡���������
�Ƕ��š�
LONG);

    set("exits", ([ /* sizeof() == 2 */
	"east" : __DIR__"duanqiao",
	"southwest" : __DIR__"pinghu",
		 ])
	 );
	set("cost", 2);
     set("fjing", 1);
        set("outdoors", "hangzhou");
    setup();
    replace_program(ROOM);
}
