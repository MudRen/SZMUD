//Cracked by Roath
// xiakedao/xkx13.c
// modified by aln 5 / 98

inherit __DIR__"no_pk_room";
int flag = 1;

void create()
{
        set("short", "ʯ��");
        set("long", @LONG
ʯ����������ϯ�ض��������Ա�Ŀ���ɣ���Ȼ����������ŵ���
�ơ�һ�������ֳּ��������ڵ������ذ�Ū���ƺ�����ռ����ż��
̧ͷ����ʯ��(wall)����������
LONG );

      set("exits", ([
		"south" : __DIR__"xiakexing4",
      ]));
	set("item_desc",([
	    "wall" : "
ǽ�����Ϸ����š�������Ȼŵ���������֡��ֵ��·�ȴ�̵���һ����
���ķ��˰���ͼ��������Щ�Ĳ����⡣һ����ע����Ի�����ھ�ʳ��
��禷������������롣����ע�ƣ�����Ի�����鼫���ؾ��ơ�����Щ
׭��Сע��������\n",
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
