// Code of ShenZhou
inherit NPC;

string ask_me();

void create()
{
        set_name("��������", ({ "oldman" }));
        set("long", 
"һ���������Ŵ�����ֵ�������������ſڣ�˦�����ĸ����ƴ�"
"��������Ҷ�����ŵ����������������ǣ���Ҳ������ڡ�\n");
        set("gender", "����");
        set("age", 78);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 26);
        set("int", 16);
        set("con", 22);
        set("dex", 24);
	set("chat_chance", 10);
	set("chat_msg", ({


"�������������̾�˿����������������ˣ�������ڳ���ɧ�Ű��գ���ٱ�����ô���ܰ���\n",      
	 }) );

        set("combat_exp", 800);
	set("inquiry", ([
	"����" : (: ask_me :),
	       ]) );

        setup();


	 carry_object("/clone/armor/cloth")->wear();

}
string ask_me()
{
       object ob;
ob = this_player();
 if ( ob->query("family/family_name") == "����μ�") {
command("say ���������ˣ���λ"+RANK_D->query_respect(ob)+"��Ϊ��ү����ȥΪ���������\n");
ob->set_temp("����1", 2);
command("addoil " + ob->query("id"));
return "Ҫ�������ʮ�ꡣ����";
}
else
{
command("say ���������ˣ�������ڳ���ɧ�Ű��գ�ƫƫû����ֹ���������°���\n");
command("sigh");

return "Ҫ�������ʮ�ꡣ����";
}
}
