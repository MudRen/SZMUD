//Cracked by Roath
// xiakedao/xkx4.c
// modified by aln 5 / 98

inherit __DIR__"no_pk_room";
int flag = 2;
void create()
{
        set("short", "ʯ��");
        set("long", @LONG
�˶������ǽ�Ϊӵ�����м��˽�̤�������Ƿ�λ�������������
�ߣ�һ�����߶����ڱ�����λ��Ŀ������ͷ������͸��˿˿��������
����������Ů�Ӳ����������ʯ��(wall)��ָָ��㡣
LONG );

      set("exits", ([
		"east" : __DIR__"xiakexing1",
      ]));
	set("item_desc",([
	    "wall" : "
ǽ�����Ϸ����š��������ǡ��������֡��ֵ��·�����һ�ŻƵ���
��ͼ�����б������Ǵ�����ԡ�����ͼע�����ơ����ǡ���Ȼ���Ӿ�
�������᱾��ĩҲ����һ��Сע����ѩ�ƽ����쪡�\n",
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
