//Cracked by Roath
// xiakedao/xkx9.c
// modified by aln 5 / 98

inherit __DIR__"no_pk_room";
int flag = 4;

void create()
{
        set("short", "ʯ��");
        set("long", @LONG
������ʯ�������Ϊ���ơ���ʯ�������ǰ�����һ����״�
��һ����ʿ��Զ��������ڻ��������֡�һ��վ��Զ��ǽ�ǣ���ǽ��
�Ļ��ȡ�����������У�������ʯ��(wall)�������ƺ��Ѿ�������ȥ��
LONG );

      set("exits", ([
		"south" : __DIR__"xiakexing3",
      ]));
	set("item_desc",([
	    "wall" : "
ǽ�����Ϸ����š��й����������������֡��ֵ��·��̵����ǡ�����
�С�ʫ���������ƵĹ��¡�ֻ��һ�˽�ü���ޣ��߹ڻ�����ȴ������
�����㣬���ʿ�֪�����������һ�˸��ݰ��룬���Ǻ�������������
��Ӱ����������ͼ��֮��Сע������\n",
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
