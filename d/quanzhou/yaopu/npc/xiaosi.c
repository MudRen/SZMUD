// Code of ShenZhou
inherit NPC;
int ask_aoyao();
void create()
{
        set_name("ҩ��С��", ({ "yaopu xiaosi","xiaosi"}) );
        set("gender", "����" );
        set("age", 17);
        set("long","���������ݣ����в�ɫ����֪�������ƹ�Ŀ̱���\n");
        set("str", 12);
        set("dex", 20);
        set("con", 13);
        set("shen_type", 0);
        set("combat_exp", 200);
        set("max_qi", 200);
        set("max_jing", 100);
        set("neili", 200);
        set("max_neili", 200);

        set("attitude", "friendly");
        set("inquiry", ([
            "��ҩ" : (: ask_aoyao :),
            "��ҩ" : (: ask_aoyao :),
            "��ҩ" : (: ask_aoyao :),
            "��ҩ" : (: ask_aoyao :),
            "ҩ¯" : "���������Լ�����ҩ����",
       ]) );
        setup();
}

int ask_aoyao()
{
	object me = this_player();
	message_vision(query("name")+"��$N���͵���\n",me);
	message_vision("���Ƚ����Ӵ�\[open lip\]��Ȼ����������ҩ��\[add **** in lu\]\n",me);
	message_vision("���ŵ�һЩˮ\[pour water\]������ҩ���յ��ˡ��ٿۺø���\[close lip\]\n",me);
	message_vision("��̿���ȼ\[burn coal\]����¯���������ˡ��Ϳ��԰�ҩ��\[aoyao\]��\n",me);
	message_vision("��ҩʱҪ��ʱ���ƻ�򣬻�Ҫ��ͣ���裬�����˵ġ�ҩ������֮��\n",me);
	message_vision("�ǵ������˻�\[mie huo\]��ȡҩ\[qu yao\]�����ⱻ���ˡ�\n",me);
	return 1;
}
