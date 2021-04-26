//Cracked by Roath
// Room: /d/beijing/gulou2.c


inherit ROOM;
#include "/d/beijing/beijing_defs.h"
#include "/d/beijing/bj_rooms.h"

int do_da(string arg);

void create()
{
	set("short", "��¥����");
	set("long", @LONG
�����ǹ�¥��¥��С���ӡ������м���һ�����˻�����������
���(gu)�������ʱ�������ʿ��������ʾ���Σ�����ȫ�Ƕ���
�ü������ӽ����и�ʿ���ڴ������
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
	"down" : __DIR__"gulou",
	]));
	
 	set("item_desc", ([
	"gu" : "һ��ţƤ�ġ��ԱߵĹ���Ѿ����ף��ɼ��Ѿ��������ˡ�\n"
		"����������̲�ס���(da)һ�£��������¾����Աߵ�ʿ����\n",
	]));
	set("no_clean_up", 0);
	set("outdoors", "beijing");
	set("cost", 2);

	setup();
	remove_call_out("auto_dagu");
	call_out("auto_dagu", 180);
}

void init()
{
    add_action("do_da", "da");
}

#define LOUD_SOUND "��¥�Ĵ�ķ���һ�������죺���ˣ��ˣ��ˡ����������������䶼Ҫ���ˡ�\n"
#define NORMAL_SOUND "��¥�Ĵ���������������ˣ��ˣ��ˡ���������\n"
#define WEAK_SOUND "һ�������Զ�����������ˣ��ˣ��ˡ���������\n"
#define FADE_SOUND "Զ��������ϡ�ɱ�Ĺ��������ˣ��ˣ��ˣ�����������\n"
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
 
void make_gu_sound()
{
    object  trav;
 
    trav = new(TRAVERSER);
    if (! objectp(trav)) return;
 
    trav->traverse(base_name(this_object()), (:visit_room:), 0);
}

int do_da(string arg)
{
    object player = this_player();
    object bing;

    if (! arg || arg != "gu") return notify_fail("��Ҫ��ʲô��\n");
    if (present("bing", environment(player)) )
	return notify_fail("����ȥ��ģ�����ʿ����ס���㡣\n");
    
    message_vision("$N���Ź�¥ʿ���ڴ���������͵�����һ�´�ġ�\n",
	player);
    make_gu_sound();
    bing = new("/d/beijing/npc/bj_bing");
    bing->move(environment(player));
    message_vision("���ڴ����ʿ�����ŵ�����������\n", player);
    player->apply_condition("bjkiller", 100);
    return 1;
}

int auto_dagu()
{
    if (HELPER->shichen() == 19) make_gu_sound();
    remove_call_out("auto_dagu");
    call_out("auto_dagu", 100);
    return 1;
}
