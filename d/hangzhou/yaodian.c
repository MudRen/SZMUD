// Code of ShenZhou
// ��������
// Dong  11/03/1996.
// Buying medicine code needed here. !!!

// NTD:  NPC and object. �����࣬��ơ�

#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{   set("short", "��������");
    set("long", @LONG
����һ����������ҩ�ã���ǽ����һ����ҩ�񡣼��������æ
���������µش�С������ץҩ��ҩ��ǰ����һ�����ӣ�����һλ����
����Ϊ�˰�������������ҽ�����ࡣ
LONG);

    set("exits", ([ /* sizeof() == 1 */ 
                   "west" : __DIR__"road25", 
                 ])
       );

	set("cost", 1);
    setup();
    replace_program(ROOM);
}