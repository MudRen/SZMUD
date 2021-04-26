// Code of ShenZhou
//  cangshuge �����
// modified by aln

inherit ROOM;

string look_shujia();

#define BOOKS_TOC   "/doc/books/toc"
#define BOOKS_DIR "/doc/books/jy/"

private mapping jybooks = ([
        "bxj"   : "��Ѫ��",
        "fhwz"  : "�ɺ��⴫",
        "lcj"   : "���Ǿ�",
        "ldj"   : "¹����",
        "sdxl"  : "�������",
        "sdyxz" : "���Ӣ�۴�",
        "sjecl" : "�齣����¼",
        "tlbb"  : "�����˲�",
        "xajh"  : "Ц������",
        "xkx"   : "������",
        "yttlj" : "����������",
        "33jxt" : "��ʮ������ͼ",
]);

void create()
{
	set("short", "��¹�����");
	set("long", @LONG
����һ���ǳ�����¥��һ����һ�ŵ����(shujia)����������ذ�����
�飬����Ŀ��Ͼ������ľ��ζ����ī���˱Ƕ�����������ǰ�¹��Ժ�Ĳ����
�ղ��������ѧ���䣬�������ˣ�ǧ�򲻿ɴ���ڴ�һ��Ϊ���������
LONG
	);
        set("item_desc", ([
                "shujia" : (: look_shujia :),
        ]));

	set("exits", ([
		"down" : __DIR__"shuyuan",
	]));

	set("cost", 0);

        set("no_fight", "1");
        set("no_steal", 1);
        set("no_sleep_room", "1");

	setup();
}

void init()
{
	add_action("do_read",      "read");
        add_action("do_exercise",  "exercise");
        add_action("do_exercise",  "dazuo");
        add_action("do_exercise",  "respirate");
        add_action("do_exercise",  "tuna");
        add_action("do_exercise",  "practice");
        add_action("do_exercise",  "lian");
        add_action("do_exercise",  "study");
        add_action("do_exercise",  "du");
}

int do_exercise(string arg)
{
        object me = this_player();
        tell_object(me, "���������黹������������\n");
        return 1;
}

string look_shujia()
{
//        this_player()->start_more(read_file(BOOKS_TOC));
        return "����һ������ܣ���������˺ܶ����Ĳ��顣\n";
}

int do_read(string arg)
{
        string jydir, filename;
        int t;

        jydir = this_player()->query_temp("jy/books");

        if( !arg ) { 
                if( stringp(jydir) )
                        return notify_fail("�������ڶ�" + jybooks[jydir] + "��\n");
                else    return notify_fail("����ѡ��һ������Ҫ�����飬ָ��Ϊ: read xxx(���Ӣ����д)��Ȼ��read n(����)��\n");
        }

        if( sscanf(arg, "%d", t) != 1 || arg == "33jxt" ) {
                if( member_array(arg, keys(jybooks)) == -1 )
                        return notify_fail("�����û���Ȿ�顣\n");
                else { 
                        this_player()->set_temp("jy/books", arg);
                        write("��ѡ�ˡ�" + jybooks[arg] + "����\n");
                        return 1;
                }
        }

        if( !stringp(jydir) )
                return notify_fail("����ѡ��һ������Ҫ�����飬ָ��Ϊ: read xxx(���Ӣ����д)��Ȼ��read n(����)��\n");

        filename = BOOKS_DIR + jydir + "/" + jydir + "-" + t + ".txt";
        if( file_size(filename) == -1 )
                return notify_fail(jybooks[jydir] + "û����һ�ء�\n");

	switch (MONEY_D->player_pay(this_player(), 200)) {
	        case 0:
                return notify_fail("���������Ǯ������ã�\n");
	        case 2:
                return notify_fail("������Ǯ�����ˣ���Ʊ��û���ҵÿ���\n");
	}

	log_file("BOOKS", sprintf("%s read %s.\n", this_player()->query("name"), filename));

	this_player()->start_more(read_file(filename));

	return 1;
}
