//Cracked by Roath
// Room: /d/beijing/zhonglou2.c


inherit ROOM;
#include "/d/beijing/beijing_defs.h"

int do_qiao(string arg);

void create()
{
	set("short", "��¥����");
	set("long", @LONG
��������¥�ϲ��С���ӡ���ͭ�����ͭ�� (zhong) �Ѿ����̣�
�Աߵ�ײ鳿�����Ҳ������ɣ���峿��ʱ�������ʿ����������ʾ��
�Σ�����ȫ�Ƕ����ü������ӽ����и�ʿ���ڴ������
LONG
	);
	set("exits", ([ 
	"down" : __DIR__"zhonglou",
	]));
	
 	set("item_desc", ([
	"zhong" : "һֻ�޴����ͭ�ӡ�\n"
		  "���̲�ס����(qiao)һ�£��������¾����Աߵ�ʿ����\n",
	]));
	set("no_clean_up", 0);
	set("outdoors", "beijing");
	set("cost", 2);

	setup();
	remove_call_out("auto_qiao");
	call_out("auto_qiao", 120);
}

void init()
{
    add_action("do_qiao", "qiao");
}

#define LOUD_SOUND "��¥�Ĵ��ӷ���һ�������죺�����������������������������䶼Ҫ���ˡ�\n"
#define NORMAL_SOUND "��¥�Ĵ�����������������������������������\n"
#define WEAK_SOUND "һ��������Զ������������������������������\n"
#define FADE_SOUND "Զ��������ϡ�ɱ��������������������������������\n"

int visit_room(string room_path, mapping info, mapping mapdb_info, mixed args)
{
  object room;

  if (strsrch(room_path, "/d/beijing/") != 0) return 1;  // prune
  room = find_object(room_path);
  if (!objectp(room)) return 0;
  if (info["dist"] < 2) {
    message("info", LOUD_SOUND, room, 0);
  }else if (info["dist"] < 8) {
    message("info", NORMAL_SOUND, room, 0);
  }else if (info["dist"] < 12) {
    message("info", WEAK_SOUND, room, 0);
  }else {
    message("info", FADE_SOUND, room, 0);
  }
  return 0;
}

void make_zhong_sound()
{
    int     i, j;
    object  trav;

    trav = new(TRAVERSER);
    if (! objectp(trav)) return;

    trav->traverse(base_name(this_object()), (:visit_room:), 0);
}

int do_qiao(string arg)
{
    object player = this_player();
    object bing;

    if (! arg || arg != "zhong") return notify_fail("��Ҫ��ʲô��\n");
    if (present("bing", environment(player)) )
	return notify_fail("����ȥ���ӣ�����ʿ����ס���㡣\n");
    
    message_vision("$N����ʿ���ڴ���͵�����һ�´��ӡ�\n",
	player);
    make_zhong_sound();
    bing = new("/d/beijing/npc/bj_bing");
    bing->move(environment(player));
    message_vision("���ڴ����ʿ�����ŵ�����������\n", player);
    player->apply_condition("bjkiller", 100);
    return 1;
}

int auto_qiao()
{
    if (HELPER->shichen() == 8) make_zhong_sound();
    remove_call_out("auto_qiao");
    call_out("auto_qiao", 120);
    return 1;
}
