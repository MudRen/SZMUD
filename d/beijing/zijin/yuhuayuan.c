//Cracked by Roath
// Room: /d/beijing/zijincheng/yuhuayuan.c

inherit ROOM;

void create()
{
	set("short", "����԰");
	set("long", @LONG
�����԰���12000��ƽ���ף�������԰�մ�ʦ�ǵľ��Ĺ�
˼�����ŵ����η�������ɫ���Բ���Űأ����ɽʯ����ǽ����
Ϊ������ʹ��������԰��ɫׯ�϶��������ڽ��������ϣ�����һ
��ͥԺ���ã��ֲ�ʧ�乬͢�����ǡ�԰�еĽ����ܶ��ǶԳƵģ�
�е����͡�װ���ϼ�Щ�仯���е���Ȼ������ͬ���������м���
�հ���Ժ�估��ľ�������������ͬʱ���ۣ����Բ�����������
���С�
LONG
	);
	set("exits", ([ /* sizeof() == 5 */
  "north" : __DIR__"shunzhenmen",
  "south" : __DIR__"kunningmen",
  "up" : __DIR__"yujingting",
  "east" : __DIR__"jiangxue",
  "enter" : __DIR__"qinandian",
 ]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
