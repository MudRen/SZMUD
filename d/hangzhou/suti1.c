// Code of ShenZhou
// �յ�֮�����
// Dong  11/03/1996.
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{   set("short", "�յ�");
    set("long", @LONG
�յ���ʫ���ն��������ֿ�������ʱ�ú���Ͳ����ɵġ��ն���
����ʫ�������£�������Ǯ���غ��ˣ����ʿŮ�����ᡣ���ź����
���ϣ���ɽʼ������ͨ��������ʮ�����ɣ�����ϯ����̿ա�������
���Ǵ�����ϱ��ǿ���š���������յ������ɱ����ϵĵ�һ������
һ�����������ŵ���һ����������
LONG);

    set("exits", ([ /* sizeof() == 2 */ 
                  "south" : __DIR__"suti2", 
                  "north" : __DIR__"road14", 
                 ])
       );
	set("cost", 1);
        set("fjing", 1);
        set("outdoors", "hangzhou");
    setup();
    replace_program(ROOM);
}
