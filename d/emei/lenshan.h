// Code of ShenZhou
void init() {
    remove_call_out("shine");
    call_out("shine", 5+random(5));
    add_action("do_lingwu", "lingwu");
}

int shine() {
    object me = this_object();
    object *inv = all_inventory(me);
    object player;
    int i;

    for (i=0; i<sizeof(inv); i++) {
   	player = inv[i];

	if (environment(player) != me) continue;
	if (player->query_skill("linji-zhuang", 1) < 150) continue;
	if (player->query_temp("lenshan/canlingwu") == 1) continue;

	tell_object(player, "�㿴�������չ���������, ֦Ҷ����ʵ��, ���в���һ��.\n");
	player->set_temp("lenshan/canlingwu", 1);
    }
    return 1;
}

int do_lingwu() {
    object player=this_player();
    int neili, force, ljz;

    if (player->query_temp("lenshan/canlingwu")!=1) return 0;
    if ((ljz=player->query_skill("linji-zhuang", 1)) < 180) {
	return notify_fail("����ټ�ׯ��򲻵�, �޷�����.\n");
    }
    if ((force=player->query_skill("force", 1)) < ljz*2/3) {
	return notify_fail("��Ļ����ڹ���򲻵�, �޷�����.\n");
    }
    if (player->query("jingli") < 100 ||
	player->query("qi") < 100 ||
	player->query("neili") < 200 ||
	player->query("jing") < 200) {
	return notify_fail("������״̬����, �޷�����.\n");
    }
    if (! SKILL_D("linji-zhuang")->valid_learn(player)) {
	return notify_fail("�����ڼ������������ײ, �����ѵ�.\n");
    }

    message_vision("$N��������, Ĭ���������Ǭ��Ų�Ƶ�Ҫּ, ��������.\n",
	player, 0);
    neili=player->query("neili");
    player->set("neili", 100);
    player->set("jing", 100);
    
    // normal lian (zxg, htqg) costs 60 neili to gain 1+force/5
    // points, here we do the same.
    player->improve_skill("linji-zhuang", force*(neili-100)/300);
    return 1;
}
