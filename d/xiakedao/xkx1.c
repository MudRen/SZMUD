//Cracked by Roath
// xiakedao/xkx1.c
// modified by aln  5 / 98

inherit __DIR__"no_pk_room";

int flag = 1;

void create()
{
        set("short", "ʯ��");
        set("long", @LONG
���ǵ�һ��ʯ�ҡ�������������ȥ���Ѿ���Ϊӵ������Щ���е�
עĿ��˼���еĴ����������еı�Ŀ��������е����ڴ������硣
�����ǿ��ĥ�⻬�Ĵ�ʯ��(wall)��ʯ���Ե�ȼ�Ż�ѣ�������ʯ��
��ҫ�ð�����¡�
LONG );

      set("exits", ([
		"south" : __DIR__"xiakexing1",
      ]));
	set("item_desc",([
	    "wall" : "
ǽ�����Ϸ����š��Կ��Ϻ�ӧ���������֡��ֵ��·�����һ��ͼ��ͼ
����һ�������������ֳ��ȣ����ַ��ƣ���̬��������������������
һ��ע���ƣ�������͸�Ӳ�����֡���������С�֣��������顣\n",
	]));

	set("indoors", "xiakedao" );
	set("cost", 0);
      set("objects",([
            __DIR__+"npc/laozu.c" : 1,
            __DIR__+"npc/jiumo.c" : 1,
            ]));
	setup();


}

void init()
{
        ::init();

	add_action("do_study", "study");
}

#include "/d/xiakedao/xkx.h"
