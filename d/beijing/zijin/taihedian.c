//Cracked by Roath
// Room: /d/beijing/zijincheng/taihedian.c

inherit ROOM;

void create()
{
	set("short", "̫�͵� ");
	set("long", @LONG
�׳ƽ��ǵ�ֳƷ����ʼ���ǻʵ۾��е���Ĵ���
��35�ף����2370��ƽ���ס��ν�����ʮ�ֺ���������ƽʱ�ǲ�
�õ�,��Ҫ���ھ���ʢ�����,�����ʵۼ�λ,�ʵ۴��,�����ʺ�,����
����,�Լ�ÿ��Ԫ��,����,����(�ʵ�����)�����������ٹٳ��ؼ���
��ȡ�

����Ǿ�����֪��̫�͵ ���ǵ��������ټ��ٹٺͽ��������
��ĳ����� �ھŽװ����̨���ϣ� �������ڽ�ɫ������(chair) �ϣ�
�����ڳ��� ������������С�ĵ�ע���κο��ܷ���������� Ⱥ���鸩
�ڵأ����� "���꣡ ���꣡ �����꣡"��
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"zhonghedian",
  "south" : __DIR__"guang1",
]));
	set("item_desc", ([ /* sizeof() == 1 */
  "chair" : "����һ�ſ���ľ���Σ� �α��ϵ��ž���Ϸ��� 
ͼ���� ����ϸһ���� ������Ӿ�Ȼ��ҹ���顣
",
]));
	set("objects", ([ /* sizeof() == 1 */
  "/d/beijing/npc/long" : 1,
]));
	set("no_clean_up", 0);
	set("valid_startroom", 1);

	setup();
	replace_program(ROOM);
}
