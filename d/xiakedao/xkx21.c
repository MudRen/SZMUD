//Cracked by Roath
// xiakedao/xkx21.c
// modified by aln 5 / 98

inherit __DIR__"no_pk_room";
int flag = 4;

void create()
{
        set("short", "ʯ��");
        set("long", @LONG
���ű������һ��ԭ���Ϸ���һ���������ͨ��ף���������
ʯ���ǰ����ơ�һĨ����ӿ���͸�룬Ͷ�ڶ����ʯ��(wall)�ϡ���
��Ҳ�������������ȸߴ��ɹ�������Ƭ�̼��������⡣
LONG );

      set("exits", ([
		"south" : __DIR__"xiakexing6",
      ]));
	set("item_desc",([
	    "wall" : "
ǽ�����Ϸ����š����������㡹�������֡��������Ǵ���ʱ��һ��
���ҵĹ��¡�Ҫ�����ɡ�����Ҫ����ļȰ������ֶ��ۣ���һ��ɱ
��ֱ�����˻��ǡ�һ��ע�ƣ�������ʫ���뵱ʩ��ʱ������Ħ���
��ע��߳������Ʊ�ɫ��\n",
	]));

	set("indoors", "xiakedao" );
	set("cost", 0);
      set("objects",([
            __DIR__+"npc/miejue.c" : 1,
            __DIR__+"npc/zhou.c" : 1,
            ]));
	setup();
}
void init()
{
        ::init();
	add_action("do_study", "study");
}

#include "/d/xiakedao/xkx.h"
