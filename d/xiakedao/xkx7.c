//Cracked by Roath
// xiakedao/xkx7.c
// modified by aln  5 / 98

inherit __DIR__"no_pk_room";
int flag = 2;

void create()
{
        set("short", "ʯ��");
        set("long", @LONG
��������������ϰ�书������Ů�Ӷ��Ե������ĵã���ɫ���ص�
������ʯ��(wall)��ϰ�������Աߵ�������������ȴ�����Ի��ƺ�
δ���ž���
LONG );

      set("exits", ([
		"west" : __DIR__"xiakexing2",
      ]));
	set("item_desc",([
	    "wall" : "
ǽ�����Ϸ����š����˷���ȥ���������֡��ֵ��·��̵������е�һ
��Ů�ӣ��������磬�������������Ҳ���������ơ�����ע�ƣ�С��
���ƣ����޼���ס����һ��ע�����ߣ�����֮����\n",
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
