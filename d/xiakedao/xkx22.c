//Cracked by Roath
// xiakedao/xkx22.c
// modified by aln 5 / 98

inherit __DIR__"no_pk_room";
int flag = 12;

void create()
{
        set("short", "ʯ��");
        set("long", @LONG
ֻ����ž֮�����ϣ������������Ӹ�����ü��������ӡ֤�书��
һ�Ե�����ȴ��Ĭ����������ָ�������ڿ��������̡�һ����Ůб
��ʯ��(wall)������ƣ�룬�Ҳ೤�����Ӷ���һ�̵��ģ���ɫ��ע��
LONG );

      set("exits", ([
		"north" : __DIR__"xiakexing6",
      ]));
	set("item_desc",([
	    "wall" : "
ǽ�ϡ���������Ӣ����������������б�����¡����ϼ����¸�������
Сͼ�������ֳֹ��������Σ����޹��¡�ͼ�༰����֮�������ܲ�С
ע��һ��ע�ƣ��Ĳѻ��硣��һ��ע����Ի��Ԫ�����ϣ�������Ҳ��\n",
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
