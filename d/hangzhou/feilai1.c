// Code of ShenZhou
// ������
// Dong  11/03/1996.
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{   set("short", "������");
    set("long", @LONG
�ֽ�ͨ�춴���ڶ��ڵ��ұ��Ͽ�����̬���죬һ�ɶ�ߵķ�����
�����·������鸡��ǰһ���������ɮȡ���Ĺ��£���һ��Ϊ��
���Ծ������С��÷�����������Ħ�ڡ���������������ɽ��·��С·
����������������
LONG);
    set("exits", ([ /* sizeof() == 2 */ 
        "northwest" : __DIR__"feilai2", 			
        "eastdown" : __DIR__"feilai0", 			
                ])
       );
	set("cost", 3);
    setup();
    replace_program(ROOM);
}