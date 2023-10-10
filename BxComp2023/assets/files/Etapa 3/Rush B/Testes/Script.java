import java.util.Random;
class Script {
    public static void main(String[] args) {
        Random rand = new Random(001);
        int num_casos = 100;
        int num_partes = 10;
        System.out.println(num_casos);
        int num_digitos = 1;
        for(int i = 0; i < num_partes; i++) {
            for(int k = 0; k < num_casos / num_partes; k++) {
                for(int j = 0; j < num_digitos; j++) {
                    System.out.print(rand.nextInt(9));
                }
                System.out.println();
            }
            num_digitos++;
        }
    }
}
