//Cracked by Roath
// xiakedao/xkx17.c
// modified by aln  5 / 98

inherit __DIR__"no_pk_room";
int flag = 9;

void create()
{
        set("short", "ʯ��");
        set("long", @LONG
�������֮��������һ����İ�С�ĺ����ֳֻƽ������ʹ��ü
�̵��ٸ�˫սһ�����ӡ���������һƬ�ƹ������λζ���˿��������
�硣���о��缤��֮�£����ҲϨ������֧��ʯ��(wall)�ϵ�ͼ����
Լ�ɼ���
LONG );

      set("exits", ([
		"south" : __DIR__"xiakexing5",
      ]));
	set("item_desc",([
	    "wall" : "
ǽ�����Ϸ����š����Իӽ�鳡��������֡������ͼ������׳������
�����ˡ����������´��ƽ�����˴���������ֻ����ǹ���գ�Ѫ
���ɡ��Ա�ע�Ͳ��࣬���Ǳ����۽���\n",
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
