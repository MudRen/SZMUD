//Cracked by Roath
// xiakedao/xkx8.c
// modified by aln 5 / 98

inherit __DIR__"no_pk_room";
int flag = 2;

void create()
{
        set("short", "ʯ��");
        set("long", @LONG
ʯ�����У�һλ��üɮ�˺�һλ����֮���������书��һ����Ů
���Ա߲��籼�У�����֮�ʣ�����������Ǻ�г������һ����ɫ��м
��վ��ǽ�ǣ���ָ��ʯ��(wall)����ָժ���˵���ʽ��
LONG );

      set("exits", ([
		"east" : __DIR__"xiakexing2",
      ]));
	set("item_desc",([
	    "wall" : "
ǽ�����Ϸ����š�������������������֡��ֵ��·��̵���һ������
�˿ڵĹ��£��������ʩ�������ˣ����ۺ��ϡ�ֻ��ͼ����Ů��Ŀ��
�飬�Ա��Ƿ����΢Ц������µ�ˮ�Ƶ�������Զ����ɫ����һ�塣
\n",
	]));

	set("indoors", "xiakedao" );
	set("cost", 0);
      set("objects",([
            __DIR__+"npc/huang.c" : 1,
            __DIR__+"npc/yideng.c" : 1,
          ]));
	setup();
}
void init()
{
        ::init();
	add_action("do_study", "study");
}
#include "/d/xiakedao/xkx.h"
