//Cracked by Roath
// xiakedao/xkx6.c
// modified by aln 5 / 98

inherit __DIR__"no_pk_room";
int flag = 2;

void create()
{
        set("short", "ʯ��");
        set("long", @LONG
���ʯ����ȴǡ�����˹ۿ�ͼ�ף��˵����������壬���ڴ�����
����������ǽ�ϻ�Ѿ�����ȼ���ţ�ż��������΢�ıϲ�֮��������
��������֬����ζ��ʯ��(wall)Ҳ��Ѭ���˼�����
LONG );

      set("exits", ([
		"north" : __DIR__"xiakexing2",
      ]));
	set("item_desc",([
	    "wall" : "
ǽ�����Ϸ����š�ǧ�ﲻ���С��������֡��ֵ��·�����ͼ��������
һ����ͨ�������Զ��һ�����������֣������̳����𣬽�������
���е�����֯��һƬ���Աߵ�ע�����࣬һʱҲ���ϲ��塣\n",
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
