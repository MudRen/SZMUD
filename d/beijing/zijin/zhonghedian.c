//Cracked by Roath
inherit ROOM;

void create()
{
	set("short", "�к͵�");
	set("long",  @LONG
�����ֳƻ��ǵ�м���������ε�ʵ���̫�͵�ٰ���
ǰ��һ���ڴ�׼�������⣬ÿʮ��һ�εĽ���������ʵ۵ļ��ף���
ʽҲ�ڴ˽��С�


����һ��С�����һ�ż����ʵĴ󴲺�һ�ſ������Ρ�ÿ��
�ʵ��ϳ��۵�ʱ�����ͻص�������Ϣһ������ڴ���ɢ���ż�����
�飬�����ǻʵ���ĥʱ���õġ�
LONG
	);

	set("exits", ([
		"north" : __DIR__"baohedian",
		"south" : __DIR__"taihedian",
        "west"  : __DIR__"xiaodao1",
        "east"  : __DIR__"xiaodao2",
	]));

	setup();
	replace_program(ROOM);
}
