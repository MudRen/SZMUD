//Cracked by Roath
// xiakedao/xkx23.c
// modified by aln 5 / 98

inherit __DIR__"no_pk_room";
int flag = 13;

void create()
{
        set("short", "ʯ��");
        set("long", @LONG
ʯ�������������ţ���������������һ�ˣ�����һ����ɫ���Ƶ�
Ů�Ӷ��ơ���Ů����������������������Ͼ��ʱ�һ��ʯ��(wall)��
���ŵ�����Ҳ���������ơ�һ�������ֱֳ�ī���ڵ�����д��Ĩ��ҡ
ͷ���Եغ��ǵ��⡣
LONG );

      set("exits", ([
		"west" : __DIR__"xiakexing6",
      ]));
	set("item_desc",([
	    "wall" : "
�������֡�˭������¡����Ҳ�ֱ�š����ͼ�ϻ����һ���������ߣ�
���Զ������١�ֻ�����������ң�����������ϵ�΢ЦҲ�������š�
һ�е�����ע�ƣ��������¾��У��ս����������顣��ע�������¾���
�ƣ����ߵ�֮�������ߵ�֮�á�\n",
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
