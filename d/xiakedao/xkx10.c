//Cracked by Roath
// xiakedao/xkx10.c
// modifiedy by aln 5 / 98

inherit __DIR__"no_pk_room";

int flag = 3;

void create()
{
        set("short", "ʯ��");
        set("long", @LONG
����ȴҲ�������������һ�˺��ԣ����ǹ���ƣ�룬�Ѿ�����˯
ȥ��һ�������������ֶ���������������ʯ��(wall)����������վ
��һλ��ò�ٸ����ԱߵĻ�ѽ�Ҫȼ����ҡҷ���������Ϻ������˶�
����һЩ����ı��С�
LONG );

      set("exits", ([
		"north" : __DIR__"xiakexing3",
      ]));
	set("item_desc",([
	    "wall" : "
ǽ�����Ϸ����š��ѽ�ϥǰ�᡹�������֡��ֵ��·�δ��ͼ����ֻ��
���СС���Ը�������д����ע�͡�һ�в����ǣ��Ź���ʫ�ƣ�һ��
�������ķ�����һ��������ʯ�������ɽˮͨ־��������ʯ���ݳ�
�ƽ����������죬���˶�Ĥ�ݡ���Ϊ�ὣ���������ȼ���ӬͷС����
����������֮��\n",
	]));
      set("objects",([
            __DIR__+"npc/hong2.c" : 1,
            __DIR__+"npc/su.c" : 1,
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
