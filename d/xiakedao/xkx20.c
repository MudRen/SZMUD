//Cracked by Roath
// xiakedao/xkx21.c
// modified by aln 5 / 98

inherit __DIR__"no_pk_room";
int flag = 1;

void create()
{
        set("short", "ʯ��");
        set("long", @LONG
������������������������ʵ����˱��ˣ������Բ�֮���ƺ�Ҫ
վ�����ȡ���λ�������ڳ��л����ڹ������������߸����𡣼�����
���߾�����ʯ��(wall)��������ɫ���š�
LONG );

      set("exits", ([
		"east" : __DIR__"xiakexing5",
      ]));
	set("item_desc",([
	    "wall" : "
ǽ�����Ϸ����š��źմ����ǡ��������֡��·�ͼ����Ϊ�򵥣�����
һ�������ڿն���Զ��ȴ���ƻ���̫��֮�Ρ�һ��ע��д��ͼ����
�У��ղ��ɾã��᲻���ء�ͼ����ע��������͡��������գ�������
��Ȼ��\n",
	]));
      set("objects",([
            __DIR__+"npc/ailao.c" : 1,
		__DIR__+"npc/gaolao.c" : 1,
            __DIR__+"npc/du-e.c" : 1,
            __DIR__+"npc/du-jie.c" : 1,
            __DIR__+"npc/du-nan.c" : 1,
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
