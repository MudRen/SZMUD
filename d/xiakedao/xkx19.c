//Cracked by Roath
// xiakedao/xkx19.c
// modified by aln 5 / 98

inherit __DIR__"no_pk_room";
int flag = 11;

void create()
{
        set("short", "ʯ��");
        set("long", @LONG
���ＫΪ�Ͱ�������Ը�֮�˱�Ҫ��ͷ�����ڽ���������һ֧��
�ѣ�����ľ���ȼΪ�ҽ����谵�Ĺ����У�����һ����ϥ����������
ʯ��(wall)�Ȼ��š�ֻ����ָ���棬�����ޱȡ�
LONG );

      set("exits", ([
		"west" : __DIR__"xiakexing5",
      ]));
	set("item_desc",([
	    "wall" : "
ǽ�����Ϸ����š�ǧ���׳ʿ���������֡��·�����������캥����
Я�ֶ��У����ǹŷ硰�����С�ԭ�⡣����һ��С������Ի��֪����
ˮ��������ɽ��֪�߶������߾�����ע��ׯ����ˮƪ����֪��ʱֹ��
��ӯ��β��к֮��\n",
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
