//Cracked by Roath
// xiakedao/xkx18.c
// modified by aln 5 / 98

inherit __DIR__"no_pk_room";
int flag = 10;

void create()
{
        set("short", "ʯ��");
        set("long", @LONG
ʯ��֮��ƽƽ���棬Ҳ�������д��书����ָ��ʯ��(wall)�໥
���ۡ�ż������ĬȻ��������ͷ������������ˮ������ش˴�����Ϫ
��֮�¡�����ʯש�ϱ鲼��̦������С�ı�Ҫ������
LONG );

      set("exits", ([
		"north" : __DIR__"xiakexing5",
      ]));
	set("item_desc",([
	    "wall" : "
��ǽ�ϡ��������𾪡��������ֿ������ֱ�š�����ͼ����Ϊ���أ�
����һֻ����̤��ƽ�أ������������֮�ϼ���������а�����֮
�࣬�໥������Ҳ������֡��ײ���ע��׳��ֺ�����ף����ڡ�\n",
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
