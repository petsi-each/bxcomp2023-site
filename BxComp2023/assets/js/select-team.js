const characters = document.querySelectorAll('.character');
const characterImage = document.querySelector('.character-image img');

characters.forEach(character => {
    character.addEventListener('click', () => {
        characters.forEach(c => c.classList.remove('selected'));
        character.classList.add('selected');
        const imgSrc = character.getAttribute('data-img');
        characterImage.setAttribute('src', imgSrc);
    });
});
