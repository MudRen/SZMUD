//Cracked by Roath
// xiakedao/xkx11.c
// modified by aln  5 / 98

inherit __DIR__"no_pk_room";

int flag = 5;

void create()
{
        set("short", "ʯ��");
        set("long", @LONG
���ű�������г������أ���������������������ɽ��֮�ʡ���
��Ҳ�ǻ���������Ĭ�������ظ�����ϰ�书�����ȴ��֪Ϊ�����˼�
֧��ʯ��(wall)��Ͷ���˴�Ƭ��Ӱ��
LONG );

      set("exits", ([
		"west" : __DIR__"xiakexing3",
      ]));
	set("item_desc",([
	    "wall" : "
ǽ�����Ϸ����š�������캥���������֡��ֵ��·��̵����������
���캥�Ĺ��¡���˵���캥ɱ��Ϊ��������֮��̻�سֵ��������⺷
֮ɫ��κ�����޼���һ��վ������ɫ������\n",
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
