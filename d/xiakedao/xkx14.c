//Cracked by Roath
// xiakedao/xkx14.c
// modifiedy by aln 5 / 98

inherit __DIR__"no_pk_room";
int flag = 4;

void create()
{
        set("short", "ʯ��");
        set("long", @LONG
�������������ˮ��ʱ����ͷ����ʯ���ϵ��£�������Щù����
��ʯ���յ����������Ͽ̵���ͼ���֡��Ҳ�һλ����ؤ���ڶ��Ŷ���
ʯ��(wall)��ȭ��ȭ��ʮ�㡣
LONG );

      set("exits", ([
		"north" : __DIR__"xiakexing4",
      ]));
	set("item_desc",([
	    "wall" : "
����ǽ���ּ�ȴ���ڲ�ͬ���������֡�������Ϊ�᡹�������С��ڴ�
�ֵıȻ��м䣬�����ܵ�һ�ζ�Сע����ǳ��һ��ԶԶ��ȥ��ȴ����
��ͼ����ʶ��һ��ע�ǣ���Ի��ɽ�������𣬾����Գͷ�������\n",
	]));
	set("objects",([
            __DIR__+"npc/hong.c" : 1,
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
