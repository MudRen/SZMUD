              
// /d/changan/eroad2.c
// ��һ���޸�
// by bravo
// 02-1-3
// �ļ�����  ����  

inherit ROOM;

void create ()
  {
set("short", "���������");
set("long", @LONG
���ϵ����������е����ţ�·��ż�����������������������ǳ����ǵ���
Ѱ���ĺõط�������Ů�����ӱ���Ŀ�ջ�߳����������Ǹ���̨���ǵ�������
Ϊѡ�����ո�ǿ��������ʿר�������ġ�ÿ�����ﶼ��֪����������Ѳ�顣
LONG);

set("exits",([
		"east" : __DIR__"eroad3",
		"west" : __DIR__"eroad1",
		"south" : __DIR__"leitai",
		"north" : __DIR__"kezhan",
	]));
set("outdoors", "changan");
set("fanhua", 1);
setup();
replace_program(ROOM);
   }
