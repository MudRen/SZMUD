//Cracked by Roath
// xiakedao/xkx3.c
// modified by aln 5 / 98

inherit __DIR__"no_pk_room";
int flag = 2;
void create()
{
        set("short", "ʯ��");
        set("long", @LONG
���з���������������Ӱ���ڶ���Ѹ���쳣�ر��ܣ�ֱ��������
���硣һ��������Ʈ�ݣ���һ��������Ƚ�������һ����������֮
����ȴҲʮ��Ѹ�ݡ����˱�����أ�Բ�ͣ���ۣ�����������ƽ������
��ʯ��(wall)��Ҳ����ͼ���֡�
LONG );

      set("exits", ([
		"west" : __DIR__"xiakexing1",
      ]));
	set("item_desc",([
	    "wall" : "
ǽ�����Ϸ����š������հ����������֡��ֵ��·�����һƥ����
���ױ��У���������������������������з���һ�㡣ֻ��һ������
���ƺ��ڲ�����ǰ��ӿ��ֱ�������Ʊڷɳ���\n",
	]));

	set("indoors", "xiakedao" );
	set("cost", 0);
//      set("objects",([
//            __DIR__+"npc/wei-yixiao.c" : 1,
 //           ]));
	setup();


}
void init()
{
        ::init();
	add_action("do_study", "study");
}

#include "/d/xiakedao/xkx.h"
