// Code by ShenZhou
// donglang2.c ��������
// Jiuer * for door

#include <room.h>

inherit ROOM;

void create()
{
    set("short", "��������");
    set("long", @LONG
������һ���ľ��������ϣ���Լ�����������ߴ������������ƺ�������
������������������һ���ţ�door ���������������š��ϱ��Ǽ��������͵�
���ӣ�ʮ�ֵ����ţ�����Ʈ��һ����Ĳ��㣬��������ϸ��ز�֪˵Щʲô��
����Ů���ӡ��Գԡ�Ц��������
LONG
    );

    set("exits", ([
		"south" : __DIR__"chashi",
		"west" : __DIR__"donglang1",
		"north" : __DIR__"xiuxishi1",
    ]));                                                  
   
	create_door("north", "ľ��", "south", DOOR_CLOSED);

	set("cost", 1);
    setup();
}
