//Cracked by Roath
// xiakedao/xkx16.c
// modifiedy by aln 5 / 98

inherit __DIR__"no_pk_room";
int flag = 1;

void create()
{
        set("short", "ʯ��");
        set("long", @LONG
���ű����ü��ٵĺ���֮����ֻ��һ������ʯ��(wall)��������
ͷ�ʶ�����Ϣ�����������������˽�Ҫ��ͷ����һ����˫�ư���ǰ
�˵ĺ��ģ�ͷ��Ҳ�ǰ����뵡�
LONG );

      set("exits", ([
		"east" : __DIR__"xiakexing4",
      ]));
	set("item_desc",([
	    "wall" : "
����ǽȴ�����洦�������������������������������档���Ͽ̵���
������װ��Ů����̬��˳��ӯ������бб��һ��ע��������ʫ������
ܱ�Ķ�������������������������һ��ע�ּ��ʲݣ��������Ҳ�ա�\n",
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
