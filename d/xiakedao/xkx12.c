//Cracked by Roath
// xiakedao/xkx12.c
// modified by aln  4 / 98

inherit __DIR__"no_pk_room";

int flag = 6;

void create()
{
        set("short", "ʯ��");
        set("long", @LONG
��Լ�ǵ��������ڴ�ʯ��֮�ʣ����������վ�˲����ˡ�����
������һ����ɮ�ֳִ󻷵�������֮����������������������������
����¡��������µ����걳��ʯ��(wall)���ƺ����ǳ�����
LONG );

      set("exits", ([
		"east" : __DIR__"xiakexing3",
      ]));
	set("item_desc",([
	    "wall" : "
ǽ�����Ϸ����š�����Ȱ�������������֡������ͼȴ����ʫ�����
��ɡ��ǻ�����һ���ֲֳ񵶵��Է򣬱��ϼ���¡�𡣼�ʮ��ľ���
���ֱ�����ҵ�ɢ��������ǰ��ͼ�������������ܵ�������Сע��\n",
	]));

	set("indoors", "xiakedao" );
	set("cost", 0);
	setup();
}
void init()
{
        ::init();

	add_action("do_study", "study");
}

#include "/d/xiakedao/xkx.h"
