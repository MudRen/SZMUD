// Code of ShenZhou
// beiming-miji.c ��ڤ�ؼ�
// AceP

inherit ITEM;
void setup()
{}

void init()
{
        add_action("do_du", "du");
        add_action("do_du", "study");
}

void create()
{
  set_name("��ڤ�ؼ�", ({"beiming miji", "beiming", "miji"}));
  set_weight(500);
  if (clonep())
  set_default_object(__FILE__);
  else {
	  set("unit", "��");
	  set("long", "����һ�������м�Ϊ���صġ���ڤ�ؼ�������¼������ʧ������ң�ɵľ����书��\n");
	  set("value", 1000000000);
	  set("material", "paper");
	  set("no_drop", "�������������뿪�㡣\n");
	  set("no_get", "�������������뿪�Ƕ���\n");
  }
}

int do_du(string arg)
{
	object me = this_player();
	object where = environment(me);
	object ob;
	mapping skill;
	
	int i = me->query_skill("beiming-shengong", 1);

	if (!(arg=="beiming miji" || arg=="beiming" || arg=="miji" || arg=="miji2"
		|| arg=="beiming miji2" || arg=="lingbo-weibu" || arg=="weibu"))
		return 0;

	if (where->query("pigging")){
		write("�㻹��ר�Ĺ����ɣ�\n");
      return 1; }

	if (me->is_busy()) {
		write("��������æ���ء�\n");
		return 1; }

	if (me->is_fighting() ) {
		write("���޷���ս����ר�������ж���֪��\n");
		return 1; }

	if (!id("beiming miji")) {	
		write("��Ҫ��ʲô��\n");
		return 1; }

	if (!me->query_skill("literate", 1) ){
		write("���Ǹ���ä����ѧ���Ļ�(literate)�ɡ�\n");
		return 1; }
	
	message("vision", me->name() + "�ó�һ������ѧϰ��һ�����\n", environment(me), me);
	
	if ((arg=="beiming miji2"
		|| arg=="weibu"
		|| arg=="miji2"
		|| arg=="lingbo-weibu")
		&& me->query_skill("beiming-shengong",1))
	{
		if (me->query("jing") < 25 ) {
			write("�����ڹ���ƣ�룬�޷�ר�������ж���֪��\n");
			return 1; }

		if (me->query("per")<20) {
			write("����˰����貨΢��������Ҳ����������������Ĳ�������ô�ߡ�\n");
			return 1; }

		if (me->query_skill("literate", 1) < (me->query_skill("lingbo-weibu")-30)) {
			write("��Ķ���д��ˮƽ������û����ᱱڤ�ܼ��ˡ�\n");
			return 1; }

		if (me->query_skill("lingbo-weibu",1) > 200) {
			write("���ж���һ��������Ƿ���������˵�Ķ�����Զ�̫ǳ�ˣ�û��ѧ���κζ�����\n");
			return 1; }

		me->receive_damage("jing", 25);
		me->improve_skill("lingbo-weibu", (int)me->query_skill("literate", 1)/3+1);
		write("���ж�����ڤ�ؼ������貨΢������������\n");
		return 1; }

	if (me->query("gender") == "����") {
		write("�ٺ٣���ѧ���˱�ڤ������\n");
		return 1; }

	if (me->query("class") == "bonze") {
		write("������������������ô�ܶ���ڤ�ܼ�������\n");
		return 1; }
	
	if ((int)me->query_skill("force", 1) < 10
		|| (int)me->query_skill("force", 1)< (i-30)) {
		write("��Ļ����ڹ�����㣬�޷�ѧϰ��ڤ�񹦡�\n");
		return 1; }

	if ((int)me->query_skill("literate", 1) < (i-30)) {
		write("��Ķ���д��ˮƽ������û����ᱱڤ�ܼ��ˡ�\n");
		return 1; }

	if (me->query_skill("beiming-shengong",1) > 99) {
		if ((int)me->query("jing") < 40 ) {
			write("�����ڹ���ƣ�룬�޷�ר�������ж���֪��\n");
			return 1; 
		}
	}
	else {
		if ((int)me->query("jing") < 25 ) {
			write("�����ڹ���ƣ�룬�޷�ר�������ж���֪��\n");
			return 1; }
	}

	if ((int)me->query("combat_exp") < (int)i*i*i/10 ) {
		write("���ʵս���鲻�㣬��ڤ���޷�������ˡ�\n");
		return 1; }

	if (me->query_skill("beiming-shengong", 1) > 200){
		write("���ж���һ��������Ƿ���������˵�Ķ�����Զ�̫ǳ�ˣ�û��ѧ���κζ�����\n");
		return 1; }

	if (!me->query_skill("beiming-shengong", 1))
	{
		if (me->query_skill("hunyuan-yiqi",1)
			|| me->query_skill("huntian-qigong",1) 
			|| me->query_skill("taiji-shengong",1)
			|| me->query_skill("zixia-shengong",1)
			|| me->query_skill("linji-zhuang",1)
			|| me->query_skill("hamagong",1)
			|| me->query_skill("huagong-dafa",1))
		{
		write("�㲻��ɢ�˱����ڹ��ķ���û����ʼѧϰ��ڤ�񹦡�\n");
		return 1; }

		me->set_skill("beiming-shengong", 0);

write("                   ����ڤ�ؼ���\n\n"
"    �����ĵ�һ��д���ǣ�����ڤ�񹦡���\n"
"������ԴԴ������Ůͼ�񣬻������ԣ�����ǰ�أ����ֺ󱳣�һ����ʮ����ͼ��\n"
"ÿ���������ɫϸ�ߣ�ע��Ѩ����λ�����������ȵȣ���������ڤ�񹦵ķ��š�\n\n"
"    �����ľ�ͷ���š��貨΢������\n"
"��������������ӡ��ע�������á������������Ⱦ��ǡ��׾����еķ�λ��ֻ����\n"
"ӡ�������飬��֪���м�ǧ�ٸ�����һ����ӡ����һ����ӡ�����������ӣ����ϻ�\n"
"�м�ͷ����һ�׷������Ṧ������\n"
"���һ��д�������ǿ�У��Դ˱�����������������ȡ������\n\n\n"
"ѧϰ��ڤ��ע�����\n"
"һ. Ҫѧϰ��ڤ�񹦱��ȷ��������ڹ��ķ���\n\n"
"��. ��ڤ�������ܴ󣬵������Լ��������㣬�������н��������������ڡ�\n"
"    ��������һ������֮�󣬿�����ս����������ȡ���˵�������\n\n"
"��. ����ڤ�ؼ����������ˣ����ۣ���������ʰ��Ψһ�Ļ�ȡ�������㵽ָ��\n"
"    �ĵط�����������ȡ�á�\n\n"
"��. ��ڤ����ʦ�ɰݣ�Ҳ����ͨ���Լ�������������ֻ����ϰ����ڤ�ؼ���\n"
"    ������ߡ�\n\n"
"��. ��ڤ�񹦶Ի�������Ҫ��ܿ��̣��޷����������ڹ���ʮ�����ϣ������\n"
"    ��д�ֵ��ڱ�ڤ����ʮ�������޷���������ڤ�ؼ�����\n\n"
"��. ��ڤ�񹦳�����ȡ�����⣬����һЩ�ر���;������ϸ�����ɡ�\n\n"
"         ���վ�ͨ��ڤ�񹦣���ؿɳ�Ϊ���ֵ�һ���֣�\n"); }

	if (me->query_skill("beiming-shengong", 1)<100)
		me->receive_damage("jing", 25);
	else me->receive_damage("jing", 40);

	me->improve_skill("beiming-shengong", me->query_skill("literate", 1)/3+1);
	write("���ж�����ڤ�ؼ�������ڤ������������\n");
	return 1;
}