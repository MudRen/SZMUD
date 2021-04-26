// Code of ShenZhou
// Summer 9/26/1996.

inherit NPC;
int ask_tea();
void create()
{
	set_name("С����", ({ "xiao lama", "xiao", "lama" }));
	set("long", 
"�����ղ��С���������ɫ���ģ��������Ÿ�����ף� \n"
"����������ظ����ǰæ����\n");
	set("gender", "����");
	set("age", 20);
	set("attitude", "peaceful");
	set("class","bonze");
	set("shen_type", 1);
	set("str", 22);
	set("int", 20);
	set("con", 22);
	set("dex", 21);
	
	set("max_qi", 300);
	set("max_jing", 300);
	set("neili", 100);
	set("max_neili", 100);
	set("jiali", 10);
	set("combat_exp", 1000);

	set_skill("force", 20);
	set_skill("dodge", 25);
	set_skill("parry", 20);
	set_skill("strike", 20);
	set("inquiry", ([
                "���Ͳ�" : (: ask_tea :),
	]));

	setup();
	carry_object(__DIR__"obj/lamajiasha")->wear();
}
int ask_tea()
{
	say("С����һ�����ͷ��������������Ȳ�����˵�о��У����ţ� \n");
	this_player()->set_temp("marks/��", 1);
	return 1;
}
int accept_object(object who, object ob)
{
	object tea; 
	if (ob->name()!="����") {
	write("С����Ц�úϲ�£�죺��������" + RANK_D->query_respect(who)+ "��\n");
        return 1;
        }
                        write(
"С�����ͷ��������������" + RANK_D->query_respect(who)+" �����ò衣\n");
        who->delete_temp("marks/��");
        tea=new("/d/qilian/obj/buttertea");
	tea->move("/d/qilian/chufang");
	tea=new("/d/qilian/obj/buttertea");
	tea->move("/d/qilian/chufang");
	tea=new("/d/qilian/obj/buttertea");
        tea->move("/d/qilian/chufang");
        return 1;

}
void destroy (object ob)
{
        destruct(ob);
}
