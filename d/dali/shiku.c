// Code of ShenZhou

inherit ROOM;

void create()
{
	set("short", "����ʯ��");
	set("long", @LONG
    ʯ��ɽ�У���ʯǧ����̬�����������ɽ������گ�������屦��ʮ�߸���
�̾�ϸ���������������ݶ��أ��ط�����ɫ��Ũ����ʯ�ߡ���Щʯ�߷ֲ���ʯ��
ɽ��ʯ���£�ʨ�ӹأ�ɳ��������������ʮ������ĵش���Լ����һ����ʮ����
LONG
	);
	set("cost", 1);
	set("outdoors", "dali");

	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
