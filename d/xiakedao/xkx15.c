//Cracked by Roath
// xiakedao/xkx15.c
// modified by aln 5 / 98

inherit __DIR__"no_pk_room";
int flag = 8;

void create()
{
        set("short", "ʯ��");
        set("long", @LONG
�������Ũ�أ����������˲��پƴ����«����������˵���Ѿ�
�������壬أ�������ﲻͣ���ƣ����ĵ�ģ��ʯ��(wall)�ϵ�ͼ����
�����������һ��Ů���ڱǶ�����������֮ɫ��
LONG );

      set("exits", ([
		"west" : __DIR__"xiakexing4",
      ]));
	set("item_desc",([
	    "wall" : "
ǽ�����Ϸ����š��ۻ������᡹�������֡�����̵���³��������ɽ
�ŵĹ��£����е��ֺ��д������࣬Ω��ΩФ�������ֻ���������Ҷ��
�����衣\n",
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
