//Cracked by Roath
// xiakedao/xkx5.c
// modified by aln 5 / 98

inherit __DIR__"no_pk_room";
int flag = 3;

void create()
{
        set("short", "ʯ��");
        set("long", @LONG
һλ�ɷ���ǵ���������һλ�ߴ���������д��书�����˾���
��ֿս�����ʽ������������󾢷罫���ڵĻ�Ѽ���������������
ʯ��(wall)�ϵ�ͼ�����ǰವ½�롣
LONG );

      set("exits", ([
		"south" : __DIR__"xiakexing2",
      ]));
	set("item_desc",([
	    "wall" : "
ǽ�����Ϸ����š�ʮ��ɱһ�ˡ��������֡����µ�ͼ��ȴ��һ������
ɽˮ�������ɽ�����֣�����ľ��֦�����̲�һ��ǰ���ݺᣬ��Ҳ��
���۽�������������ͼ��������Сע��\n"
	]));

	set("indoors", "xiakedao" );
	set("cost", 0);
      set("objects",([
            __DIR__+"npc/ouyang.c" : 1,
            __DIR__+"npc/ding.c" : 1,
          ]));
	setup();
}
void init()
{
        ::init();
	add_action("do_study", "study");
}
#include "/d/xiakedao/xkx.h"
